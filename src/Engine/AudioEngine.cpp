#include <iostream>
#include <fstream>
#include <cstring>
#include <Utils.hpp>
#include <AL/al.h>
#include <AL/efx.h>
#include <AL/alc.h>
#include <Core/Log.hpp>

#include <Engine/AudioEngine.hpp>

AudioEngine::AudioEngine()
{
}

AudioEngine::~AudioEngine()
{
}

void AudioEngine::init()
{
    device = alcOpenDevice(NULL);
    if (device == NULL)
    {
        Log::error("cannot open sound card");
        return;
    }
    
    context = alcCreateContext(device, NULL);
    if (context == NULL)
    {
        Log::error("cannot open context");
        return;
    }
    alcMakeContextCurrent(context);
}

int AudioEngine::load(const char *path)
{
    byte buffer[4];
    std::ifstream in(path, std::ios::binary);
    if (in.fail())
    {
        return AudioErrorCode::FILE_NOT_FOUND;
    }

    in.read(buffer, 4);
    if (strncmp(buffer, "RIFF", 4) != 0)
    {
        return AudioErrorCode::FILE_INVALID;
    }
    in.read(buffer, 4);
    in.read(buffer, 4); // WAVE: File Type Header
    if (strncmp(buffer, "WAVE", 4) == 0)
    {
        int chan, samplerate, bps, size;
        byte *data = loadWAV(path, chan, samplerate, bps, size);
        this->audioData = AudioData{
            data,
            chan,
            samplerate,
            bps,
            size};
        return AudioErrorCode::OK;
    }
    return AudioErrorCode::UNKNOWN;
}

byte *AudioEngine::loadWAV(const byte *fn, int &chan, int &samplerate, int &bps, int &size)
{
    byte buffer[4];
    std::ifstream in(fn, std::ios::binary);

    // https://docs.fileformat.com/audio/wav/
    in.read(buffer, 4); // File size
    in.read(buffer, 4); // WAVE: File Type Header
    in.read(buffer, 4); // fmt: Format chunk marker. Includes trailing null
    in.read(buffer, 4); // 16: Length of format data as listed above
    in.read(buffer, 2); // 1:  Type of format (1 is PCM) - 2 byte integer
    in.read(buffer, 2); // 2: Number of Channels - 2 byte integer
    chan = convertToInt(buffer, 2);
    in.read(buffer, 4); // Sample Rate
    samplerate = convertToInt(buffer, 4);
    in.read(buffer, 4); // Sample Rate * BitsPerSample * Channels) / 8
    in.read(buffer, 2); // (BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
    in.read(buffer, 2); // Bits per sample
    bps = convertToInt(buffer, 2);
    in.read(buffer, 4); // data header
    in.read(buffer, 4); // File size (data):	Size of the data section.
    size = convertToInt(buffer, 4);
    char *data = new char[size];
    in.read(data, size); // data

    in.close();

    return data;
}

void AudioEngine::play()
{
    unsigned int bufferid, format;
    alGenBuffers(1, &bufferid);
    if (audioData.channels == 1)
    {
        if (audioData.bps == 8)
        {
            format = AL_FORMAT_MONO8;
        }
        else
        {
            format = AL_FORMAT_MONO16;
        }
    }
    else
    {
        if (audioData.bps == 8)
        {
            format = AL_FORMAT_STEREO8;
        }
        else
        {
            format = AL_FORMAT_STEREO16;
        }
    }

    alBufferData(bufferid, format, audioData.data, audioData.size, audioData.sampleRate / 3 * 10);

    unsigned int sourceid;
    alGenSources(1, &sourceid);
    alSourcef(sourceid, AL_PITCH, .1f);
    alSourcei(sourceid, AL_BUFFER, bufferid);
    alSourcePlay(sourceid);
    alEnable(AL_SPEED_OF_SOUND);
    alSpeedOfSound(20.0f);
}

void AudioEngine::dispose()
{
    //     alDeleteSources(1, &sourceid);
    //     alDeleteBuffers(1, &bufferid);

    //     alcDestroyContext(context);
    //     alcCloseDevice(device);
    //     delete[] data;
    //     return 0;
}
#pragma once
#include <Types.hpp>

class ALCdevice;
class ALCcontext;

struct AudioErrorCode
{
    enum Type
    {
        OK = 0,
        FILE_NOT_FOUND = 1,
        FILE_INVALID = 2,
        UNKNOWN = 100,

    };
};

struct AudioData
{
    byte *data;
    int channels;
    int sampleRate;
    int bps;
    int size;
};

class AudioEngine
{
    AudioData audioData;
    ALCdevice *device;
    ALCcontext *context;

public:
    AudioEngine();
    virtual ~AudioEngine();

    void init();
    int load(const char *path);
    byte *loadWAV(const char *fn, int &chan, int &samplerate, int &bps, int &size);
    void play();
    void dispose();
};

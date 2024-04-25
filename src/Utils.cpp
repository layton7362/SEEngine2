// bool isBigEndian()
// {
//     int a = 1;
//     return !((byte*)&a)[0];
// }

// int convertToInt(byte* buffer, int len)
// {
//     int a = 0;
//     if (!isBigEndian())
//         for (int i = 0; i<len; i++)
//             ((byte*)&a)[i] = buffer[i];
//     else
//         for (int i = 0; i<len; i++)
//             ((byte*)&a)[3 - i] = buffer[i];
//     return a;
// }
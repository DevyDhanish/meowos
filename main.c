void main()
{
    char *video = (char *) 0xb8000;
    video[0] = 'X';
    video[1] = 0x1f;
}
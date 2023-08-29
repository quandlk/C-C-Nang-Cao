    {
        // sum += va_arg(va, int);
        printf("%f\n", va_arg(va, double));
    }
    va_end(va);
    printf("-----------------\n");
    va_start(va,num);
    char *conTro = &va;
    printf("%p\n", conTro);
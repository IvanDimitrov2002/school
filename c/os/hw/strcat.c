char* strcat( char* destination, const char* source ){
    int i,k;

    for(i=0;destination[i]!='\0';i++);

    for(k=0;source[k]!='\0';k++){
        destination[i+k]=source[k];
    }

    destination[i+k] = '\0';

    return destination;
}
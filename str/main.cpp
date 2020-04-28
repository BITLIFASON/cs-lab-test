#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const size_t MAX_SIZE = 256;
const char* forbidden =  "*<>?|\"";

int main()
{
    char text[MAX_SIZE];
    cout << "Enter file name: ";
    fgets(text, MAX_SIZE, stdin);
    char* filename = text;
    printf("before |%s|\n", text);
    filename[strlen(filename) - 1] = '\0';
    printf("after |%s|\n", text);
    while(true) {
        if( strcspn( filename, forbidden ) == strlen( filename ) ) ;
        else {
            cout << "Invalid format";
            break;
        }

        if( strchr( filename, ':' ) == nullptr ) ;
        else {
            char* colon = strchr(filename,':');
            if( colon - filename != 1 ) {
                cout << "Invalid format";
                break;
            }
            //while( colon != nullptr ) {
                if( isalpha( filename[colon - filename - 1] ) > 0 &&
                    filename[colon - filename + 1] == '\\');
                    //colon = strchr(colon + 1, ':');
                else {
                    cout << "Invalid format";
                    break;
                }
            //}
        }

        if( strrchr( filename, '.' ) == nullptr )
            strcat( filename, ".txt" );

        else {
            char* ext = strrchr( filename, '.' );
            for( int i = 1; ext[i] != '\0'; i ++ )
                *(ext + i) = char(tolower(*(ext + i)));
            if( strncmp( ext, ".txt", MAX_SIZE + 1 ) == 0 ) ;
            else {
                cout << "Invalid format";
                break;
            }
        }

        FILE* file = fopen( filename, "r" );
        if( file == nullptr ) {
            cout << "Invalid file name";
            break;
        }
        fseek( file, 0, SEEK_END );
        long filesize = ftell( file );

        char* filedata = new char[filesize+1];
        rewind( file );
        fread( filedata, 1, filesize, file );
        filedata[filesize] = '\0';

        char STR[MAX_SIZE];
        cout << "Enter string: ";
        fgets(STR, MAX_SIZE, stdin);
        char* str = STR;
        *( str + strlen(str) - 1 ) = '\0';

        int occur = 0;
        while( *filedata != '\0'  ) {
           if( strncmp( filedata, str, strlen(str) ) != 0 )
                filedata += 1;
           else {
                occur ++;
                filedata += 1;
           }
        }
        cout << "Occurance number: " << occur;

        delete[] filedata;
        fclose( file );
        break;
    }
    return 0;
}

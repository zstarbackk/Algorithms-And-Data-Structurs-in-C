#include "testing.h"
int createTxtPrueba(){
    FILE * pf = fopen(ARCH_TXT, "w");
    t_person vec[]={
        {10,"Lio Messi",'C'},
        {9,"Juli Alvarez",'S'},
        {30,"Mastantuono",'M'},
    };
    if(pf==NULL){
        return -1;
    }
    for(int i = 0; i < sizeof(vec)/sizeof(t_person);i++){
        fprintf(pf,"%d|%s|%c\n",vec[i].id, vec[i].username,vec[i].rol);
    }
    fclose(pf);
    return 1;
}
int createBinPrueba(){
    FILE * pf = fopen(ARCH_BIN,"wb");
    t_person vec[]={
        {10,"Lio Messi",'C'},
        {9,"Juli Alvarez",'S'},
        {30,"Mastantuono",'M'},
    };
    if(pf==NULL){
        printf("error");
        return -1;
    }
    for(int i = 0;i < sizeof(vec)/sizeof(t_person); i++)
        fwrite(&vec[i], sizeof(t_person),1,pf);
    fclose(pf);
}
FILE * openFile(const char * fileName, const char * openMethod){
    FILE * pf = fopen(fileName, openMethod);
    if(pf == NULL){
        printf("Fatal Error");
        return NULL;
    }
    return pf;
}
int closeFile(FILE * pf){
    fclose(pf);
}
int readElement(FILE * pf, void *el,int (*read)(FILE *pf, void  * el)){
    if(read(pf, el))
        return 1;
    return 0;
}
int readBin(FILE *pf, void * el){
    if(fread(el, sizeof(t_person),1,pf)==1)
        return 1;
    return 0;
}

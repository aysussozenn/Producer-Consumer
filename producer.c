#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <sys/mman.h> 
#include <unistd.h> 
  
  
int main() 
{ 
    
    const int SIZE = 4096; 
  
 
    const char* name = "SM"; //Shared Memory 
  
    
    const char* firstName = "NAME = AYSU"; 
    const char* surName = "\nSURNAME = SÖZEN"; 
    const char* id="\nID = 17050111051";
    
    int fd; 
  
    
    char* ptr; 
  
    
    fd = shm_open(name, O_CREAT | O_RDWR, 0666); 
  
    
    ftruncate(fd, SIZE); 
  
     ptr=(char*)
    /*ptr =*/mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0); 
  
 
    sprintf(ptr, "%s", firstName); 
  
    ptr += strlen(firstName); 
    sprintf(ptr, "%s", surName); 
    ptr += strlen(surName); 
     sprintf(ptr, "%s", id); 
    ptr += strlen(id);
    return 0; 
} 
 


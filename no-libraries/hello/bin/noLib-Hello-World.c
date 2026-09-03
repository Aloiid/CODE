//hello friend sans librairie 

int _start (void){

const char hello[] = "Hello Friend.\n"; 

// afficher le hello
asm volatile (

"mov $1, %%rax;" // syscall write = 1
"mov $1, %%rdi;" // stdout 
"lea %0, %%rsi\n\t" //adresse de hello (on met 0 car c'est le premier input (la première valeur/argument) si y'en avait d'autres on aurait mis %1,%2 etc
"mov $14, %%rdx\n\t" //taille de hello
"syscall" //on fait un syscall (appel systeme)
: //nada
: "m"(hello) //on dit que comilateur que hello doit etre en mémoire et pas dans un registre 
:"%rax","%rdi","%rsi","%rdx" //clobbers = on préviens le compilateur des registre qu'on a modifié 

); 

//exit
asm volatile (

"mov $60, %%rax;" // syscall write = 60
"mov $0, %%rdi\n\t" // stdout 
"syscall\n\t" //on fait un syscall exit (appel systeme)
:::"%rax","%rdi" //clobbers = on préviens le compilateur des registre qu'on a modifié 
//on peut mettre dans ce format la :::
); 

return 0;

}

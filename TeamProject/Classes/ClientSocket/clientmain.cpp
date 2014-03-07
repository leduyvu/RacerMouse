#include "ClientSocket.h"
#include "Client.h"
//#include </usr/include/mysql/mysql.h>
#include <unistd.h>
#include <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
//char addr[200]="127.0.0.1";
//int port=12345;
//ClientSocket cs(addr, port);
//Client c(&cs);
void handler(int sig)
{	
//strcpy(addr,"127.0.0.1");
	//printf("Signal handler : %d\n",sig);
	//(void) signal(S , SIG_DFL);
	exit(sig);
}

//
//int main(int argc, char* argv[]) {
//   // char addr[200]="127.0.0.1";
//  //  int port=12345;
//    if(argc > 3){
//        printf("Too many arguments");
//        return 0;
//    }
//    else if(argc == 3){
//        port = atoi(argv[2]);
//        strcpy(addr, argv[1]);
//    }
//    else if(argc == 2){
//        strcpy(addr, argv[1]);
//        port = 12345;
//    }
//    else{
//        strcpy(addr,"127.0.0.1");
//        port = 12345;
//    }
//    cs.connect();
//    c.clientSocket->recv(c.package);
//    printf("%s\n",c.package.getData());
//    char* cn;
//    do {    
//        printf("%s > ", c.currentDir);
//        cn = c.readCommand();
//	    if (strcmp(cn, "login") == 0) {
//            c.login();
//        }
//        else if (strcmp(cn, "logout") == 0) {
//            if(c.logout()){
//	            break;
//	        }
//        }
//        else if (strcmp(cn, "register") == 0) {
//            c.reg();
//				
//        }
//        else if (strcmp(cn, "cd") == 0) {
//              c.cd();     
//        }
//		else if (strcmp(cn, "mkdir") == 0) {
//              c.createdir();     
//        }
//        else if (strcmp(cn, "put") == 0){
//	        c.put();
//			
//        }
//        else if(strcmp(cn, "ls") == 0){
//	        c.ls();         
//        }
//        else {
//       // if with other ftp commands (ls, cd, put, log...)
//        }
//	(void)signal(SIGINT ,handler) ;
//	(void)signal(SIGHUP ,handler) ;
//    } while (strcmp(cn, "quit") != 0);
//    cs.close();  
//    return 0;
//}


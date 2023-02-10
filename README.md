# Locker-System
A hotel room Locker system that enable the guest to put the valuable things in it and set a password, this password should never deleted even if the microcontroller power is off. If user insert 10 zeros the password will back to default value which is 0000.
Details: 
1. Pressing on any button will make the buzzer on for 100msec. 
2. First time password saved is 0000. 
3. User should enter 0000 to open locker at first time.
4. To change password user should press on ‘/’ -> buzzer will be on for 3 second then off -> user should enter 4 digit password then -> press on ‘/’ again to save password
5. To close the locker, you should press only on ‘*’ 
6. To open the locker, enter 4 digit password (lcd display * each time you enter a digit for password, then display locker opened if right password and Try again if wrong password and a buzzer will be on for 3 second then off -> re-enter password again.
7. To reset password: (locker must be in opened state): insert 10 zeros the
password will back to default value which is 0000.
![image](https://user-images.githubusercontent.com/102418786/216461512-76a73817-5e70-4ebd-b104-55c41cf58926.png)

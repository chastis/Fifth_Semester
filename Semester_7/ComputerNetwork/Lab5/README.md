# Lab 5

form: https://forms.gle/BD4UXGiF3ZKYAktK6

info:
* RJ-45 - Ethernet cable
* VLAN1 - Default virtual interface
* gateway - IP address, that used when we can refer traffic to another network. it set by admin
* address gateway - IP address of router, interface that sends packets out of the local network.
* DHCP - (Dynamic Host Configuration Protocol) technology for dynamic configuration network node

important:
* ipconfig (in cmd) | settings of network of windows
* Switch(config)# interface vlan 1 | go to vlan1 mode
* Switch(config-if)# ip address 192.168.10.2 255.255.255.0 | set ip address and netmask
* Switch(config-if)# no shutdown | disable shutdown, change state to up (launch router)
* Switch# show ip interface brief | show state interface of commutators
* C:/ping 192.168.1.253 | ping to ip interface

# HypervisorControl-win
Control the Hypervisor from Windows. ( Do a complete shutdown or reboot )
This is a mini implementation of the brhypsrv to control the hypervisor system from Windows.


# Commands
`HypervisorControl.exe `
* Returns the information if B&R Hypervisor is running (i.e.: Windows was started standalone).

`HypervisorControl.exe reboot`
 * Performs a System Reboot ("Deep Reboot") of the B&R Hypervisor system.
 * In detail, it sends shutdown commands to GPOS and ARemb. After both OSes are shutdown, the system is rebooted.
 
`HypervisorControl.exe shutdown`
 * Performs a System Shutdown ("Deep Shutdown") of the B&R Hypervisor system.
 * In detail, it sends shutdown commands to GPOS and ARemb. After both OSes are shutdown, the system is powered off.

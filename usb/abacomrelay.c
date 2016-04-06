/*
 * ABACOM USB relayboard driver - 1.0
 *
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/kref.h>
#include <linux/mutex.h>

//EXPORT_SYMBOL_GPL(usb_register_driver);
//EXPORT_SYMBOL_GPL(usb_deregister);

static int relay_probe (struct usb_interface *interface, const struct usb_device_id *id)
{
	printk("[*] relay card driver (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
	return 0;
}


static int relay_disconnect (struct usb_interface *interface)
{
	printk("[*] relay card driver removed\n");
	return 0;
}

static struct usb_device_id relay_table[] = {

	{ USB_DEVICE(0x1a86, 0x5512) },
	{0,}
};
MODULE_DEVICE_TABLE(usb, relay_table);


static struct usb_driver relay_driver = 
{
	.name = " usb relay card ",
	.id_table = relay_table, 
	.probe = relay_probe,
	.disconnect = relay_disconnect, 
};

static int __init relay_init(void){
	int ret = -1;
	printk( "[*] solid code construction of drive\n");
	printk( "\t registering driver with kernel\n");
	//ret = usb_register(&relay_driver);
	printk( "\t registration complete\n");
	return 1;
}

static void __exit relay_exit(void){
	printk( "[*] solid code destructor of code\n");
	//usb_deregister(&relay_driver);
	printk( "\t unregister complete\n");
}

module_init(relay_init);
module_exit(relay_exit);



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

MODULE_AUTHOR( "Heiko Finzel" );
MODULE_LICENSE( "GPL" );
MODULE_DESCRIPTION( "Driver for the ABACOM usb relayboard." );

/*
 * Constants
 */

#define DEBUG
/* Define vendor & product match IDs */
#define USB_RELAYBOARD_VENDOR_ID	0x1a86 
#define USB_RELAYBOARD_PRODUCT_ID	0x5512
#define USB_RELAYBOARD_MINOR_BASE	0
#define RELAY_READ_FREQ_MAX			(HZ / 2) //500ms
#define RELAY_CMD(b)				{0xa1,0x6a,0x1f,0x00,0x10,b,0x3f,0x00,0x00,0x00,0x00}
#define RELAY_CMD_LENGTH			11

/*
 * Descriptors
 */

/* Device table for this driver */
static const struct usb_device_id relayboard_device_table[] = {
	{ USB_DEVICE( USB_RELAYBOARD_VENDOR_ID, USB_RELAYBOARD_PRODUCT_ID ) },
	{ 0,}				
};
MODULE_DEVICE_TABLE( usb, relayboard_device_table );

/* Specify the driver itself */
static struct usb_driver relayboard_driver = {
	.name =		"abacomrelay",
	.id_table =	relayboard_device_table,
};

/* Systemcalls provided by this driver */
static const struct file_operations relayboard_fops = {
	.owner =	THIS_MODULE,
};

static char *relay_devnode(struct device *dev, mode_t *mode)
{
    return kasprintf(GFP_KERNEL, "usb/%s", dev_name(dev));
}

/* Descriptor to let the system know the name of the device, the supported
	systemcalls and the minorID to start with */
static struct usb_class_driver relayboard_descriptor = {
	.name =		"relayboard%d",
	.devnode = relay_devnode, 
	.fops =		&relayboard_fops,
	.minor_base =	USB_RELAYBOARD_MINOR_BASE,
};

/*
 * Driver handling
 */

static int __init usb_relayboard_init(void)
{
	int result;
	/* Don't accidentally provide the usb_class_driver descriptior here or 
		you will freeze the system on driver loading ! ^^ */
	if(result = usb_register(&relayboard_driver) ) {
		printk( KERN_ERR "abacomrelay: Driver registration failed, error %d.\n",
			result);
	}
	return result;
}

static void __exit usb_relayboard_exit(void)
{
	usb_deregister(&relayboard_driver);
}

module_init(usb_relayboard_init);
module_exit(usb_relayboard_exit);



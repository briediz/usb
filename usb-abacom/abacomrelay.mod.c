#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa6d31cde, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xe0df24d, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x1bb759d0, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x98bb3285, __VMLINUX_SYMBOL_STR(usb_find_interface) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xef602b3e, __VMLINUX_SYMBOL_STR(usb_deregister_dev) },
	{ 0x73024162, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x272ee926, __VMLINUX_SYMBOL_STR(usb_register_dev) },
	{ 0xae5289ff, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xc15d3573, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0xd19662f0, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x851fffe3, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x6b888292, __VMLINUX_SYMBOL_STR(usb_bulk_msg) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x5650c0c1, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0x733c3b54, __VMLINUX_SYMBOL_STR(kasprintf) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xc4554217, __VMLINUX_SYMBOL_STR(up) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xd0d8621b, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xdd1a2871, __VMLINUX_SYMBOL_STR(down) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v1A86p5512d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "83FE972F78A1E840F63BA2D");

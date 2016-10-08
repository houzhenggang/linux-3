/*
 * =====================================================================================
 *
 *       Filename:  statistics.c
 *
 *    Description:  G
 *
 *        Version:  1.0
 *        Created:  10/07/2016 04:17:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jintao zhao, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <linux/init.h>
#include <linux/netdevice.h>

void print_statistics(void){
		struct net_device *dev;
		dev = dev_get_by_name(&init_net,"eth0");
		while( dev != NULL ){
				struct rtnl_link_stats64 temp;
				const struct rtnl_link_stats64 *stats = dev_get_stats(dev, &temp);
				printk(KERN_INFO "dev name: %s\n", dev->name);
				printk(KERN_INFO "\ttransmitted bytes: %llu\n", stats->tx_bytes);
				printk(KERN_INFO "\treceived bytes: %llu\n", stats->rx_bytes);
				printk(KERN_INFO "\ttransmitted packets: %llu\n", stats->tx_packets);
				printk(KERN_INFO "\treceived packets: %llu\n", stats->rx_packets);
				if(strcmp(dev->name,"eth0")){
						dev = NULL;
				}else{
						dev = dev_get_by_name(&init_net,"eth1");
				}
		}

}

static int __init netbase_init(void)
{
		printk(KERN_INFO "statistics init");
		print_statistics();
		return 0;
}

static void __exit netbase_exit(void)
{
		printk(KERN_INFO "statistics exit");
		print_statistics();
}

module_init(netbase_init);
module_exit(netbase_exit);


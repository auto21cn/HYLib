 // rope.c
#include <ansi.h>
#include <weapon.h> 
inherit WHIP; 
void create()
{
        set_name( "豹尾鞭", ({ "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
        set("long", "藏边常用的牧羊鞭改制而成，牦牛皮制成，柔韧异常。\n");
                set("value", 5000);
                set("material", "skin");
        }
        ::init_whip(75); 
        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n"); 
}     

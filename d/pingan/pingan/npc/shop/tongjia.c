// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tongjia.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("熟铜甲", ({"bronze armor","tongjia","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
       set("long", "一件金灿灿的熟铜甲。\n");
                set("value", 2200);
                set("material", "steel");
                set("armor_prop/armor", 35);
     set("armor_prop/dodge", -15);
             }
         setup();
}

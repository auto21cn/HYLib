// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIW "ˮ��Ь" NOR, ({ "crystal shoes", "shoes"}) );
       	set("long", "����һ˫��Ь��\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "ˮ��");
		set("unit", "˫");
		set("value", 5000);
		set("armor_prop/armor", 33 );
		set("armor_prop/personality", 33);
		set("female_only", 1);
	}
	setup();
}

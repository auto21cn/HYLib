// gangzhang.c ����

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("ħ����", ({ "lingshezhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص�ħ���ȡ�\n");
		set("value", 20000);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
  	init_staff(300);
	setup();
}
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIY"����"NOR, ({ "jia sha", "sha" }) );
  set("long", "һ��������˵����ġ�\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "cloth");
    set("armor_prop/armor", 15);
    set("armor_prop/spells", 10);
    set("armor_prop/dodge", 10);
  }
  setup();
}

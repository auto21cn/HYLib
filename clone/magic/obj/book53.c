// ���Է�������

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void create()
{
        set_name(BLU"������������"NOR, ({ "dfield axes", "53axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ħ���������ʹ��(spell id)�����ħ����\n") ;

                set("unit", "��");
                set("value", 140000);
                set("zhen", 1);
        }
        setup();
}

void init()
{
        add_action("do_shot","spell");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();

 	if (!id(arg))
	return notify_fail("���޷�ʹ���������!\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");


	
        if(me->query("magicgift")==5 )
                return notify_fail("���Ѿ��ǰ�������!!\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"BLU"�ϵ�ħ������������!  $N"BLU"��ʧ�ˡ�\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("dfield axes", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(BLU"\n$N"BLU"����Χ�γ���һ�����εĺڰ�����!��\n"NOR,this_object(),me);
        me->set("magicgift",5);
        this_object()->add("zhen", -1);
        me->start_busy(1) ;
        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"BLU"�ϵ�ħ������������!  $N"BLU"��ʧ�ˡ�\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        return 1;
}
// ���ں���������

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
        set_name(HIB"���㵯"NOR, ({ "ruanxiang dan", "dan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ʹ�õĳ�������������ʹ��(use)\n") ;

                set("unit", "��");
                set("value", 150000);
                set("zhen", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","use");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;
        int damagic;
        string msg;
        object weapon;
        me = this_player();

 	if (!id(arg))
	return notify_fail("���޷�ʹ�����!\n");
	
        if( !arg ) return notify_fail("�����˭ʹ�ã�\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");




if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("�Է�������С��û��Ҫʹ�ã�\n");
	
        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");


        if( !objectp(ob = present("ruanxiang dan", me)) )
                return notify_fail("��û�����ֶ�����\n");

if (target->is_busy())
return notify_fail("���������ù������˵�ʱ�򰡣�\n");
                me->start_busy(1);
        message_vision(HIB"\n$n"HIB"΢΢һЦ,�ӳ���һ����ɫ������ !!  \n"NOR,this_object(),me);
         msg = HIB"$N"HIB"����$n"HIB"�ӳ���һ����ɫ��������\n"NOR;
        msg += HIB"$n"HIB"ͻȻ���أ�����������������֮��!!\n"NOR;
if (userp(target))
{
target->set_temp("apply/intelligence", 0);
target->set_temp("apply/strength",0);
target->set_temp("apply/dexerity",0);
target->set_temp("apply/constitution",0);
target->set_temp("apply/karey", 0);
target->set_temp("apply/percao", 0);	
target->set_temp("apply/armor", 0);
target->set_temp("apply/defense", 0);
target->set_temp("apply/attack", 0);
target->set_temp("apply/damage", 0);   
me->start_busy(1);
}
else
{
me->start_busy(1);
target->set_temp("apply/intelligence", 0);
target->set_temp("apply/strength",0);
target->set_temp("apply/dexerity",0);
target->set_temp("apply/constitution",0);
target->set_temp("apply/karey", 0);
target->set_temp("apply/percao", 0);	
target->set_temp("apply/armor", 0);
target->set_temp("apply/defense", 0);
target->set_temp("apply/attack", 0);
target->set_temp("apply/damage", 0);   
}
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);


if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
        destruct(this_object());
        return 1;
}
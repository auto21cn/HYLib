// ci.c  �̼�ʽ
// congw@CCTX

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���̼�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("liancheng-jian", 1) < 50 )
		return notify_fail("������ǽ���������죬����ʹ�á�\n");
	                        
	if( (int)me->query_skill("force", 1) < 50 )
		return notify_fail("��Ļ����ڹ������ߡ�\n");
			
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á��̼��ԡ���\n");
			
	msg = HIY "ֻ��$N����һ�����������������벻���ķ�λ����$n����硣\n"NOR;



             if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
          if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
        if( !target->is_busy() )
{
	target->start_busy( (int)me->query_skill("liancheng-jian") / 50 + 1);
}	
}
		
		damage = (int)me->query_skill("liancheng-jian", 1);
		damage = damage +  (int)me->query_skill("liancheng-jian", 1);
		damage = damage +  (int)me->query_skill("sword", 1);
		damage = damage+600;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		target->receive_damage("jing", 80);
		me->add("neili", -100);
		msg += CYN"$nֻ�����һ���ʹ�����β��ɵ�Ϊ֮һ����\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"����$p����һ��,�����$P�Ĺ�����\n"NOR;
		me->add("neili", -100);
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
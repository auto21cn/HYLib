// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［腰斩］只能对战斗中的对手使用。\n");

        if ( me->query_temp("weapon"))
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-100);

	extra = me->query_skill("unarmed",1);
	if(extra <= 80 ) return notify_fail("你的［空手道］不够熟练！\n");
	msg = HIR "$N突然绕到$n身后，右膝猛然上顶，双手同时抓向$n，企图将$n的后腰磕断！" NOR;
        weapon = me->query_temp("weapon");
	me->add_temp("apply/damage",extra*2);
	me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
	me->start_busy(1);
	return 1;
}

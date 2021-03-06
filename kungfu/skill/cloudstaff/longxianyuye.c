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
		return notify_fail("［龙现于野］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-100);

	weapon = me->query_temp("weapon");
	extra = me->query_skill("staff",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N低呼佛号，内力聚于双臂，手中的"+ weapon->name() +"幻出一条金磷飞龙，闪电般的扑向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(1);
	return 1;
}

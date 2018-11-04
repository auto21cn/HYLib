#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���촵ѩ����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query_skill("chuixue-jian", 1) < 80)
                return notify_fail("��ĺ��촵ѩ�����ȼ��������޷�ʹ�á�������ɡ���\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        msg = HIY "$Nʹ�����촵ѩ�����������־�����ʽ��Ȼ��졣\n";

        if( random(me->query("combat_exp")) >(int)target->query("combat_exp")/4 )
        {
                attack_time = random((int)me->query_skill("chuixue-jian", 1) / 25);
                if(attack_time < 1)
                        attack_time = 1;

                msg += CYN " ���$p��$P���˸����ֲ�����\n" NOR;
                for(i = 0; i < attack_time; i++){
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                        }

                me->start_busy(2);
                me->add("neili", -100);
        }
        else
        {

                msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

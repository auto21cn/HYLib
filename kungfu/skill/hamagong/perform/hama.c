// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hama.c 蛤蟆功

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p, ap, dp;
        string msg, dodge_skill;


                
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("蛤蟆功绝招只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("hamagong", 1) < 100 )
                return notify_fail("你的蛤蟆功还不够熟练，不能使用蛤蟆绝招对敌！\n");

        if( me->query_temp("weapon") )
                return notify_fail("你必须空手才能使用「蛤蟆功」！\n");

        if (me->query_skill_mapped("force") != "hamagong")
                return notify_fail("你的内功中无此功夫。\n");

        if (           me->query_skill_mapped("strike") != "hamagong")
                return notify_fail("你必须先将蛤蟆功运用于掌法之中才行。\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的掌法不够娴熟，使不出蛤蟆功的绝招！\n");

        if (me->query_str() < 30 )
                return notify_fail("你的力量太小，使不出用蛤蟆绝招！\n");


        if( me->query_temp("hmg_hama") )
                return notify_fail("你刚使完「蛤蟆功」绝招，目前气血翻涌，无法再次运用！\n");

        
        msg = BLU "\n$N身子蹲下，左掌平推而出，使的正是$N生平最得意的「蛤蟆功」绝招，掌风直逼$n而去！\n"NOR;        
        me->set_temp("hmg_hama", 1);
        
        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("force") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

	if (ap / 2 + random(ap) > dp)
	{                
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                damage = (int)me->query_skill("hamagong", 1) * 2;     
                damage = damage + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                msg += COMBAT_D->damage_msg(damage, "内伤");
                call_out("perform2", 0, me, target, p);    
        } else 
        {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"你但觉一股微风扑面而来，风势虽然不劲，然已逼得自己呼吸不畅，知道不妙，连忙跃开数尺。\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_combatd(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage, ap, dp;
        string msg, dodge_skill;

        if(! target || ! living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「蛤蟆功」掌风排山倒海般涌向$n！\n"NOR;   
             
        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("dodge") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

	if (ap / 2 + random(ap) > dp)   
	{     
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -300);           
                damage = (int)me->query_skill("hamagong", 1) * 2;     
                damage = damage + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                msg += COMBAT_D->damage_msg(damage, "内伤");       
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(4);
                me->add("neili", -200);
                tell_object(target, HIY"你喘息未定，又觉一股劲风扑面而来，连忙跃开数尺，狼狈地避开。\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/4, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage, ap, dp;
        string msg, dodge_skill;
  
        if (! target) return 1;
        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N双腿一登，双掌相并向前猛力推出，$n连同身前方圆三丈全在「蛤蟆功」劲力笼罩之下！\n"NOR;   
             
        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("parry") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

	if (ap / 2 + random(ap) > dp)  
        {
                me->start_busy(3);
                target->start_busy(random(2));
                me->add("neili", -400);          
                damage = (int)me->query_skill("hamagong", 1) * 2;     
                damage = damage + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                msg += COMBAT_D->damage_msg(damage, "瘀伤");
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("jingli", -100);
                tell_object(target, HIY"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", me->query_con()/3, me);
        message_combatd(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("hmg_hama");
        tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「蛤蟆功」绝招了。\n"NOR); 
}



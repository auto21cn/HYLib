// migong lev3

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(BLU"�ڹھ���"NOR, ({ "ju mang" , "mang" }));
                set("race", "Ұ��");
       set("long",
"һֻ��Ȼ������������,����Ҫһ�ڰ������¡�
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
	       set("max_qi",3500+random(1500));
  set("max_jing",3500+random(1500));
  set("max_qi",3500+random(1500));
  set("max_mana",1500+random(1500));
  
      set("dex",40);
     set("str" ,60);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 1200000);
                  
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);

   setup();

        

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;   
              me->add("score",1);
        message_vision(WHT"$Nž��һ��̱���ڵ��ϡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 1800000)   {
        message("vision", me->name() + "�ɹ���������������50�����25Ǳ�ܡ�\n", me);
        me->add("combat_exp",50);
        me->add("potential",25);
        destruct(ob);
        }
               destruct(ob);
        return;
}



int hit_ob(object me, object ob, int damage)
{
   if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 30);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
	}
}
// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("����", ({ "ju mang" , "mang" }));
      
          set("race", "Ұ��");
       set("long",
"һ���˳����������ߡ�\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
	       set("max_qi",1800+random(800));
  set("max_jing",1800+random(800));
  set("max_sen",800+random(800));
  set("max_mana",800+random(800));
  
      set("dex",30);
     set("str" ,35);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 800000);
                  
        set_temp("apply/attack", 90);
        set_temp("apply/damage", 90);
        set_temp("apply/armor", 90);
        set_temp("apply/defence",90);

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
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + "�ɹ���������������40�����20Ǳ�ܡ�\n", me);
        me->add("combat_exp",40);
        me->add("potential",20);
        destruct(ob);
        }

               destruct(ob);
        return;
}


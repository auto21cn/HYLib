// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(YEL"金钱豹"NOR, ({ "bao" }));
      
          set("race", "野兽");
       set("long",
"一双发亮的眼睛死死的盯着你看
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	       set("max_qi",1700+random(700));
  set("max_jing",1700+random(700));
  set("max_sen",700+random(700));
  set("max_mana",700+random(700));
  
      set("dex",45);
     set("str",35);
       
    set("age", 5);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 700000);
                  
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
        message_vision(WHT"$N一声惨叫,倒在地上，翻了个跟头就不动弹了。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + "成功打死猎物增加了40经验和20潜能。\n", me);
        me->add("combat_exp",40);
        me->add("potential",20);
        destruct(ob);
        }
               destruct(ob);
        return;
}

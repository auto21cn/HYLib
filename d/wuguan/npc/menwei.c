// by dubei
inherit NPC;
#include <ansi.h>
void create()
{
	int age = 20 + random(20);
	set_name("�������", ({ "men wei", "menwei", "wei" }));
	set("gender", "����");
	set("age", age);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set("apply/attack", 30);
	set("apply/defense", 30);
	set("apply/damage", 35);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	add_money("silver", 3+age/10);
        carry_object("clone/cloth/cloth")->wear();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	}
	
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
//                  if ( ob->query("combat_exp") < 10000)  
//       command("say ��λ" + RANK_D->query_respect(ob)+"���书��ô���ô�������أ�\n");
       if ( ob->query("combat_exp") > 10000  && ob->query("combat_exp") < 80000 ){ 
         command("say ���书���и���������Ѿ��޷��ٰ���������ˣ���λ" + RANK_D->query_respect(ob)+"����Ҳ������Եһ����\n");
       if (ob->query("enter_wuguan",1) ) ob->delete("enter_wuguan");
           command("say ����˵����������ڹ�������Ӣ�۵ֿ��ɹţ�����ǰȥͶ����һ��������������������㻹������Ϳ���"CYN"(help guojob)"NOR"��\n");
            message_vision("$N��������һЦ��������׼��������ݡ�����Ӵ���Ȼ�����ն��Լ�ҲҪ��־��һ�����£�\n", ob);
}
      if ( ob->query("combat_exp") > 100000)  
       command("say ����ֻ�����������֣��书��ǿ�Ͳ�Ҫ�ٻ����ˣ�");
}

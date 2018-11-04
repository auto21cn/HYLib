// chen.c �½���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_weiwang();
int ask_tuihui();
int ask_job();
int ask_fail();
string ask_me();
int do_gongzuo();
int ask_done();
mapping *changxi = ({ 
         ([ "changxi":"����","where":"city"   ]),
         ([ "changxi":"����","where":"city2"  ]),
         ([ "changxi":"�ɶ�","where":"chengdu"]),   
         ([ "changxi":"����","where":"dali"   ]),   
         ([ "changxi":"��ɽ","where":"foshan" ]),   
         ([ "changxi":"Ȫ��","where":"quanzhou"]),   
         ([ "changxi":"����","where":"hangzhou"]),   
         ([ "changxi":"����","where":"lingzhou"]),   
         ([ "changxi":"����","where":"suzhou"]),   
         ([ "changxi":"����","where":"lanzhou-city"]),   
         ([ "changxi":"�ྩ","where":"yanjing"]),   
         ([ "changxi":"����","where":"jingzhou"]),   
         ([ "changxi":"����","where":"kunming"]),   
         ([ "changxi":"����","where":"xiangyang"]),   
         ([ "changxi":"����","where":"changan"]),   
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
	set_name("�½���", ({ "chen jinnan", "chen","jinnan" }));
	set("title", HIR "��ػ�"HIM"�ܶ���"NOR );
	set("nickname", HIC "Ӣ���޵�" NOR);
	set("long", 
		"\n����һ����ʿ����������������ɫ�Ͱ���\n"
		"������������������ػ��ܶ����½��ϣ�\n"
		"��˵ʮ�˰����գ�������ͨ��\n"
		"ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 300);
	set_skill("yunlong-xinfa", 300);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 300);
	set_skill("yunlong-jian", 320);
	set_skill("yunlong-shenfa", 300);
	set_skill("yunlong-bian", 300);
	set_skill("yunlong-shou", 300);
	set_skill("yunlong-zhua", 300);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	create_family("������",1, "��ɽ��ʦ");
	set("book_count", 1);
        set("inquiry", ([
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ������ػᣬ�������λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
		"��������" : (: ask_me :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
		"�˻�" : (: ask_tuihui :),
		"tuihui"   : (: ask_tuihui :),
                "��������" : (: do_gongzuo :),
                "work"  : (: do_gongzuo :),
                "done" : (: ask_done    :),
                "���" : (: ask_done    :),
                "����" : (: ask_done    :),
	]) );
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		"\n�½���ҡͷ̾�����۵��������������������������Ǻο���?\n",
		(: command("smile") :),
		(: command("poem") :),
		(: command("nomatch") :),
		(: command("haha") :),
		(: command("chat ��λ" + RANK_D->query_respect(this_player())+",������ԩ�޳𣬺α����?\n") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "blade.duan" :),                
	}) );
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/d/city/obj/gangdao");
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ������澭���ڴ˴���";
        add("book_count", -1);
        ob = new("/clone/book/yljianpu");
        ob->move(this_player());
        return "�ðɣ��Ȿ���������ס����û�ȥ�ú����С�";
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("yunlong-shengong", 1) < 50)
	{
		command("say �����������ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ�����������϶��µ㹦��");
		return;
	}
	if ((int)ob->query("weiwang") <60)
	{
		command("say ���������书�����޵У��������ţ�\n�ش����������������壬Ϊ���²���ı������\n"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ȳ�ȥ��һ�������������춯�صĴ��£�");
		return ;
	}
	if ((int)ob->query("shen") >0&&(int)ob->query("shen") < 5000) {
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return ;
	}
	if(ob->query("weiwang")<80)
	{
		if((int)ob->query("shen")<0)
 command("say "+ RANK_D->query_respect(ob) +"��Ȼ��а�����ˣ���Ҳ������Щ���¡�\n");
		command("chat ����ػ�������Ϊ����һ����ǰ����δ��֮�¡�\n");
		command("chat ���¿������ң��������ţ������Ȼ���ֺ����ۣ�\n");
		command("chat �����������ɣ���\n");
		command("chat �벻����һ��������ҵ�������������˴��ˣ�����������������\n");
		message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,this_player());
		ob->set("weiwang",80);
	}
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="chen" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ���Ӳ��ܲ쿴��\n"); 
		return 1;
	}

	command("tell "+ob->query("id")+" �����еĻ����书���£�\n"+
	"  �������� (blade)                         - ��ɲ� 200/   \n"+
	"  ����צ�� (claw)                          - ��ɲ� 200/   \n"+
	"  �����Ṧ (dodge)                         - ��ɲ� 200/    \n"+
	"  �����ڹ� (force)                         - ��ɲ� 200/    \n"+
	"  �����ַ� (hand)                          - ��ɲ� 200/    \n"+
	"  ����ȭ�� (unarmed)                       - ��ɲ� 200/    \n"+
	"  �����޷� (whip)                          - ��ɲ� 200/    \n"+
	"  �����м� (parry)                         - ��ɲ� 200/    \n"+
	"  �������� (sword)                         - ��ɲ� 200/    \n"+
	"  �����ķ� (yunlong-xinfa)                 - ��ɲ� 300/    \n"+
	"  ����д�� (literate)                      - ��ɲ� 200/    \n");
	command("tell "+ob->query("id")+" �����еĸ����书���£�\n"+
	"����ȭ (houquan)                           - ��ɲ� 300/    \n"+
	"���廢���ŵ� (wuhu-duanmendao)             - ��ɲ� 300/    \n"+
	"�������� (yunlong-shengong)              - ��ɲ� 300/    \n"+
	"���������� (yunlong-shenfa)                - ��ɲ� 300/    \n"+
	"���������� (yunlong-jian)                  - ��ɲ� 320/    \n"+
	"�������� (yunlong-bian)                    - ��ɲ� 300/    \n"+
	"�������� (yunlong-shou)                    - ��ɲ� 300/    \n"+
	"������צ (yunlong-zhua)                    - ��ɲ� 300/    \n");
	return 1;
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say("\n�½���˵�������������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
	+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("�½�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}
int ask_tuihui()
{
	object ob;
	ob=this_player();

	if(ob->query("party/party_name") != HIR "��ػ�" NOR )
	{
message_vision("�½���Ц��Ц����$N˵�����㻹û��������ػ��أ���ʲô�ˣ�\n", ob);
		return 1;
	}
	if(ob->query("family/family_name") == "������" )
	{
message_vision("�½��ϰ�������$N˵�������Ѿ����������ŵ��ӣ�������˻᣿\n", ob);
		return 1;
	}
	command("look "+ob->query("id"));
	command("sigh ");
	command("say ���帴������Ҫ����־ʿ����ȥ��! ");
	ob->delete("party");
	ob->delete("rank");
	ob->delete("level");
	return 1;
}                                           

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�ȷ�����ʿ����û��ô���ף��㻹�����߾���������");
                return 1;
}
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵������²���,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����!!");
                return 1;
        }

        if (me->query("kill_yunlong") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "���帴������Ҫ����־ʿ����ȥ��!");
                command("say " + me->query("id") + " ��һ��������ʿ��ץ�ˣ�Ҫ�������ǣ�Ҫ�ڡ�" + quest["short"]             + "��·������ȥ���˰ɣ�\n" NOR);
                me->set("kill_yunlong", 1);
                me->set("quest/quest_type", "��");
                me->set("quest/quest", "������ʿ");
                me->set("task_time", time() + 300);
                ob = new(__DIR__"shangdui",1);
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_yunlong") == 1) {
                command("pk1");
                command("say �ҿ������ˣ���ֻ���ɱ���ȥ�ȷ�����ʿ,����150��POT.");
                me->add("potential",-50);
                me->delete("kill_yunlong");
                me->apply_condition("menpai_busy",10);
                return 1;
                }
}

int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("yljob2/changxi")>0)
    {
                tell_object(me,HIW"���ȥ�����帴���������ɣ�\n"NOR);
                return 1;
    } 
        if ((int)me->query_condition("yl2_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵�����Ҫ������,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }

        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(HIC"�½��϶�$N˵������ȥ" + changxi["changxi"] + "ȥ�������帴���ĵ����ɡ�\n"NOR,me); 
        me->set_temp("yljob2/changxi", 1);
        me->set_temp("yljob2/where",changxiwhere);
        me->set_temp("yljob2/cx",changxi["changxi"]);

me->apply_condition("yl2_busy", 3);
        ob=new(__DIR__ "ling");
        ob->move(me);
    message_vision(HIC"�½��϶�$N˵������Щ��������ȥ������(xuanchuan)�ɡ�\n"NOR,me); 
        return 1;   
}

int ask_done()
{      

        object me,ob;
int exp,pot;
exp=45+random(60);
pot=25+random(45);

        me = this_player(); 
        
        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }
  
    if( me->query_temp("yljob2/changxi")< 1)
    {
                tell_object(me,CYN"��û�����𣿡�\n"NOR);
                return 1;
    } 

    if( me->query_temp("yljob2/done")< 1)
    {
                tell_object(me,HIW"����˵����������Ŀ�Ļ�û�дﵽ����ȥ�����ɡ�\n"NOR);
                return 1;
    }
    message_vision(HIG"�½��϶�$N˵�������ò���������Щ�����ɡ�\n"NOR,me); 
    me->add("combat_exp",exp);
    me->add("potential",pot);
        me->delete_temp("yljob");
    me->delete_temp("yljob2");
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);

    return 1;
}

#include "/kungfu/class/yunlong/tiandihui.h";
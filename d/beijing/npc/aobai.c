// aobai.c
inherit NPC;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
	set_name("����", ({ "ao bai", "ao", "bai"}));
	set("long",
		"���������޵�һ��ʿ������һϮ��߽��С������Ŀ��࣬\n"
		"��ò������̫��Ѩ�߸߹����ƺ����������书��\n"
	);

	set("nickname", "���޵�һ��ʿ");
	set("title", HIC"�ٱ�"HIR"һ�ȳ��乫"HIY"���������"NOR);
	set("gender", "����");
	set("attitude", "aggressive");

	set("age", 50);
	set("shen_type", -1);
	set("str", 65);
	set("int", 25);
	set("con", 25);
	set("dex", 65);
	set("max_qi", 15000);
	set("max_jing", 15000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 150);
	set("combat_exp", 850000);
	set("score", 50000);

	set_skill("force", 390);
	set_skill("hunyuan-yiqi", 390);
	set_skill("dodge", 90);
	set_skill("shaolin-shenfa", 395);
	set_skill("hand", 300);
	set_skill("parry", 300);
	set_skill("literate", 55);
	set_skill("fengyun-shou", 390);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "fengyun-shou");

	prepare_skill("hand", "fengyun-shou");

        set("chat_chance_combat", 10);  
        set("chat_msg_combat", ({
                " ����ŭ������Ҳ�����˯�������������� ��\n",
                (: command("say ������������" + RANK_D->query_rude(this_player())+"!\n") :),
		(: command("pain") :),
                      }) );
        setup();
        carry_object("/d/beijing/obj/anmenkey")->wield();
        carry_object("/d/beijing/obj/jinduan")->wear();
        carry_object("/d/beijing/obj/yaodai")->wear();
        carry_object("/d/beijing/obj/yaoshi")->wield();
        add_money("gold",2);
}

void die()
{
        message("vision","\n���ݿ�е����벻����һ��������Ȼ�������֣�\n","/d/beijing/aobai6");        	 
        message("vision","���ݶ���һ�٣�̾��������ֻ��ϧ�ҵ���ô�౦������\n","/d/beijing/aobai6");        	 
        message_vision("$N����һ�������ˣ�\n", this_object());
        ::die();
}

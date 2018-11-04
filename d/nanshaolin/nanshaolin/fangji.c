// Npc: /kungfu/class/nanshaolin/fangji.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();
void create()
{
	set_name("����", ({ "fang ji", "fang", "ji"}));
	set("long", "����һλ�����Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("nickname", "ҩͷ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("luohan-quan", 50);
	set_skill("hand", 50);
	set_skill("fengyun-shou", 50);
	set_skill("qianye-shou", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("club", 50);
	set_skill("weituo-chu", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("hand", "qianye-shou");
	map_skill("strike", "sanhua-zhang");
	map_skill("club", "weituo-chu");
	map_skill("parry", "weituo-chu");
	prepare_skill("hand", "qianye-shou");
	prepare_skill("strike", "sanhua-zhang");

	set("jin_count", 3);
	set("xiao_count",6);
	set("da_count", 6);
	set("inquiry", ([
		"��ҩ" : (: ask_me_1 :),
		"С����" : (: ask_me_2 :),
		"�󻹵�" : (: ask_me_3 :)
	]));
	create_family("��������", 21, "����");
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(__DIR__"qimeigun")->wield();
}
string ask_me_1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";
	if ( present("jin chuangyao", this_player()) )
		return RANK_D->query_respect(this_player()) +"���������ϲ����п�ҩ������������Ҫ�ˣ� ����̰�����У�";
	if (query("jin_count") < 1) return "�Բ��𣬽�ҩ�Ѿ�������";
	ob = new(__DIR__"jinchuang-yao");
	ob->move(this_player());
	add("jin_count", -1);
	message_vision("$N���һ����ҩ��\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";
}

string ask_me_2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) +"���ǲ��ǸճԹ�ҩ����������Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";
	if ( present("xiaohuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) +"���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";
	if (query("xiao_count") < 1) return "�Բ���С�����Ѿ�������";
	ob = new(__DIR__"xiaohuan-dan");
	ob->move(this_player());
	add("xiao_count", -1);
	message_vision("$N���һ��С������\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";
}

string ask_me_3()
{
	mapping fam; 
	object me,ob;
	me = this_player();
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) +"���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";
	if ( (int)this_player()->query("max_neili" ) < 400)
		return RANK_D->query_respect(this_player()) +"������������ҩ����к����ˣ�����ʱ�������ɡ�";
	if ( present("dahuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) +"���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";
	if ((int)me->query("max_neili") >= (int)me->query_skill("force")*10)
		return RANK_D->query_respect(this_player()) +"���������Ҫ�أ����书�Ѿ�������ȥ���������Ϊ�ɡ�";
	if (query("da_count") < 1) return "�Բ��𣬴󻹵��Ѿ�������";
	ob = new(__DIR__"dahuan-dan");
	ob->move(this_player());
	add("da_count", -1);
	message_vision("$N���һ�Ŵ󻹵���\n",this_player());
	return "�ðɣ���ס������Σ����ͷ��Ҫ����ʹ�ô�ҩ��";
}
#include "fang.h";
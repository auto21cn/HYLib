// yinggu.c ������

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
string ask_book();
string ask_yideng();
void create()
{
int i,k,a,b,c,d,e,f,temp;
        set_name("������", ({ "liu yinggu", "liu", "yinggu" }));
        set("gender", "Ů��");
        set("nickname", CYN "������" NOR ) ;
        set("age", 42);
        set("long",
        "��������ͷ�������ƣ����ȴ����֬��һ��������Ϊ�磬��
���ϣ��°��٣�ȴ������˶�ʮ������͡�\n",);
	set("per",39);

d=60+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
	set_skill("force", 580);
        set("combat_exp", 8000000);
        set("shen_type", 1);

        set("max_neili", 200000);
        set("neili", 200000);
        set("jiali", 0);

        set_skill("force", 500);
        set_skill("kurong-changong", 500);
        set_skill("sword", 520);
        set_skill("duanjia-sword",520);
        set_skill("dodge", 550);
        set_skill("tiannan-step", 520);      //���㹦
        set_skill("unarmed", 500);
        set_skill("kongming-quan",500);     //����ȭ
        set_skill("parry", 520);
        set_skill("literate",580);

        map_skill("force", "kurong-changong");
        map_skill("sword", "duanjia-sword");
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "duanjia-sword");
        map_skill("unarmed","kongming-quan");

        set("inquiry", ([
                "�ܲ�ͨ"     : "�����������������",
                "������"     : "����Ϻ��У����ƴȱ���\n",
                "һ�ƴ�ʦ"   : (: ask_yideng :),
                "��������"   : (: ask_book :),
        ]) );
	set("book_count", 1);
	set("yideng_count", 1);
	set_temp("apply/attack", 150);
	set_temp("apply/armor", 510);
	set_temp("apply/damage", 515);
		set_temp("apply/defense",150);
        setup();
        carry_object(__DIR__"obj/black_cloth")->wear();
}

string ask_book()
{
	mapping fam; 
	object ob;

	if ( (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "�����μ�") ||
		(query("book_count") < 1) ) 
		return RANK_D->query_respect(this_player()) + 
		"˵ʲô����ʵ�ڲ����ס�";

	if (this_player()->query_skill("literate",1) < 100)
		return RANK_D->query_respect(this_player()) + 
		"��Ҫ���飿�㻹���������ء�";
	add("book_count", -1);
	ob = new(__DIR__"lbook4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�������������\n");
	return "�ðɣ��Ȿ���������������û�ȥ�ú����С�\n";
}

string ask_yideng()
{
	mapping fam; 
	object ob;
	
	if (query("yideng_count") < 1)
		return RANK_D->query_respect(this_player()) + 
		"��˵ʲô����һ�ƴ�ʦ���ǿɱ����ҡ�";
	add("yideng_count", -1);
	ob = new(__DIR__"obj/whiteobj");
	ob->move(this_player());
	ob = new(__DIR__"obj/yellowobj");
	ob->move(this_player());
	ob = new(__DIR__"obj/redobj");
	ob->move(this_player());
	return "����������ðɣ��������Ҷ����㣬��Ե���ȥ�����ɡ�\n";
}
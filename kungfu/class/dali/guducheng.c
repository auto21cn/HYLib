// guducheng.c ���Ƴ�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
	set_name("���Ƴ�", ({ "gu ducheng", "gu" }));
	set("title",  "��������" );
	set("long", "���Ǵ������Ĵ���֮һ��\n");
//�師
	set("gender", "����");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 100000);

        set_skill("force", 50);
        set_skill("dodge", 55);
        set_skill("finger", 50);
        set_skill("parry", 55);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("staff", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 55);
        set_skill("jinyu-quan", 50);
        set_skill("duanjia-sword", 50);
	set_skill("literate", 35);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	set("inquiry", ([
		"ָ���书" : (: ask_me :),
	]));
	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);

	create_family("�����μ�",19,"����");
}
#include "/kungfu/class/dali/weishi.h"; 
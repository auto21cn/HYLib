//long.c

#include <ansi.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("���ෲ", ({ "long", "dragon" }));
        set("long", "������������֮ɫ������͵��������ųơ�������������\n"
                   +"����üȫ�ף���ɫ�������红ͯ������������ʵ����͡�\n"
                   );
        set("title", "���͵���");
        set("gender", "����");
        set("age", 75);
        set("nickname", HIR "��������" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 600);
//      set_skill("yanyangong", 200);
        set_skill("jinwu-daofa", 150);
//      set_skill("xiake-zhangfa", 100);
        set_skill("lingxu-bu", 150);

      map_skill("force", "taixuan-gong");
        map_skill("dodge", "taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        create_family("���͵�",1, "����");
        set("inquiry",([
           "������" :   "������ֻ����Ե�ˣ���֪���Ƿ�������������\n",
           "ͭ��"   :   "�����û�������գ�������Ҫ�Ļ������ұ�����һ�ʡ�\n",
        ]) );

        setup();
//        carry_object("/clone/weapon/gangdao")->wield();
        add_money("gold",5);
}

void attempt_apprentice(object ob)
{
        message_vision("����������$N��ͷ��΢΢ҡ��ҡͷ��\n",ob);
//        command("recruit " + ob->query("id"));
        return;
}

int accept_object(object who, object ob)
{
        object obn;
        object room;
        object key;

        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");

        if( (string)ob->query("name") != "����ͭ��" )
        {
              message_vision("�Ҳ���Ҫ���������\n");
              return 0;
        }
        if ( (string)ob->query_temp("own") != (string)who->query("name") )
        {
              message_vision("�ⲻ��������ӡ�");
              return 0;
        }
        command(" say  ԭ���� "+(string)who->query("name")+"����"+"��ӭ���ٱ�����");

        obn=new("/d/xiakedao/obj/labazhou");
        obn->move(who);
        command(" say ���Ǳ����ز������࣬��߿ɲ��׺ȵ�����������Ҫ��һζ��<�ϳ�ʴ�Ǹ��Ĳ�>��"
           + "��" +  RANK_D->query_respect(who) + "Ҳ����Ե֮�ˣ�����Ⱥȣ�����Ч��������"
          );
        message_vision("������������һ��������",who);
        if( (int)who->query_temp("zhou") == 2)
        {
             command(" say ������ʿ��Ե����л���һ�����־���������ɣ�");
             who->set_temp("zhou", 0);
             message_vision("ֻ����һ��¡¡��������Զ������\n", this_player());
             message_vision("ֻ�����������ʯ�建�����˿�����¶��һ������������\n", this_player());
             environment(who)->set("exits/enter", "/d/xiakedao/mishi");
             room=environment(who);
             remove_call_out("close");
             call_out("close", 15, room);
             key = new("/d/xiakedao/obj/key");
     message_vision("����������ʯ�ŵ�Կ�ף�Ҳ�����͵��ϵ�ƾ֤��ϣ�������Ʊ��ܣ��������ⶪ����" +
                    "�����ɽ������ˣ��뵺ʱӦ��黹��\n", who);
             key->move(who);
             return 1;
        }
        who->set_temp("zhou", 1);
        return 1;
}
void close(object room)
{
        message("vision","��¡¡���������֮��ʯ���ֺ����ˡ�\n", room);
        room->delete("exits/enter");
}
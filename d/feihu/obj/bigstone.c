//��ʯͷ
//by steel
#include "ansi.h"
inherit ITEM;

void create()
{
  set_name("��ʯͷ",({"bigstone","stone"}) );
  set("unit","��");
  set("long",
     "����һ��ƽƽ�����Ĵ�ʯ�����������һ����״�Ŀ�(hole)��\n");
 set("no_drop",1); 
  set("no_get",1); 
  set_weight(5000);
  set_max_encumbrance(30000); 
  setup();
}
int is_container()
{
   return 1;
}

void init()
{
  add_action("do_turn","turn");
}
int do_turn(string arg)
{
   object blade,evn,*ob,stone;
   stone=this_object();
   if(!arg)
   return notify_fail("��Ť��ôѽ������?\n");
   if(arg=="blade")
   {
   evn=environment();
   if(evn!=environment(this_player())) return 0;
   
   ob=all_inventory(this_object());
   if(sizeof(ob)!=1) return 0;
   blade=ob[0];
   
     if((string)blade->query("id")!="chuangwang baodao")
   return notify_fail(HIW"�����ʲô�Ƶ���,�ж��������С�\n"NOR);
   
   if((int)this_player()->query("neili")<=1000)
   {
   message_vision(YEL"$N������������,����ת��������!\n"NOR,this_player());
   this_player()->set("neili",0);
   return 0;
   }
   this_player()->add("neili",-1000);
   message_vision(HIR"\n$N��������,���һ��:��!!!....\n\n\n"NOR,this_player());
   write("ֻ����¡¡һ������,��ʯ��Ų������,¶��һ��С����\n");
   if(!evn->query("exits/down")) 
   {
   evn->set("exits/down","/d/feihu/midong");            
   }
   call_out("close_midong",5);
  return 1;
  }
  else
  return notify_fail("������̫������!\n");
}

int close_midong()
{
  object evn,midong,stone;
  stone=this_object();
  evn=environment(stone);
  message("vision","��¡һ���죬��ʯ�ֻص���ԭλ��\n",evn);
  evn->delete("exits/down");   
  midong=find_object("/d/feihu/midong");
 if (midong)
{
  midong->delete("exits/up");
  message("vision","ͷ���Ϸ�������������"
  "����ǳ��ں����ˡ�\n",midong); 
}
  return 1;
}
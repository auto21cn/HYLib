//Room: songlin3.c ����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","����");
      set("long",@LONG
������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪
��֮�䣬һ�Ų��ڸ����������ϣ�
LONG);
      set("outdoors", "wudang");
      set("objects", ([
           __DIR__"npc/monkey": 2,
"quest/skills2/wunon/non/nontian" : 1,
	])); 
    set_temp("wayao2",2);

      set("exits",([ /* sizeof() == 1 */
          "north"  : __DIR__"songlin1",
      ]));
//      set("no_clean_up", 0);
      set_temp("wayao1",1);
      setup();
      replace_program(ROOM);
}
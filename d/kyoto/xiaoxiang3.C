// Room: d/kyoto/xiaoxiang3
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "С��");
set("long", @LONG
����һ��С���ϣ���谵���ģ�һ������ԭ��������һ����ʳ�㣬��
�۸�����˾����㡣�Ӱ߲���ǽ����Կ�������С����ʷ�ľ�Զ��
LONG );
set("exits",  ([
        "west"  : __DIR__"shangyuan4",
        "north"  : __DIR__"mianshidian",
      ]));
        setup();
        replace_program(ROOM);
}
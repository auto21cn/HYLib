// Room: d/kyoto/xiaoxiang2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "С��");
set("long", @LONG
����һ��С���ϣ���谵���ģ�һ������ԭ�������ǲ��ң����̾���
��������Ȳ����죬�㷢�����������Ĳ����������Ǹ�Ұ��Ȫ����������
��������Ȫ��ϴȥһ���ƣ����Ҳ���Խп�������С��������һ�������
��

LONG );
set("exits",  ([
        "east"  : __DIR__"shangyuan4",
        "north"  : __DIR__"chashi",
        "west"  : __DIR__"fuyewenquan",
      ]));
        setup();
        replace_program(ROOM);
}
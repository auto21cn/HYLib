#include <ansi.h>
int give_gift();
mixed *story = 
({
        "һ�죬ΤС���յ����﷢����E-mail��",
        "��С������������ⲻ�ð�����ô�������˶�Ů�˲�����Ȥ�ˣ���",
        "С�������룬��ȥ�ҿ�����˵�����ˡ���",
        "�������㣿����ɣ�������Ҳ��������Ů��û��Ȥ��",
        "С������ѽ����������������Ҳ������ܵ��ҵ��ֵܵ������ľ���",
        "      ��������Ժ���ûʲô���Ⱑ��",
        "�����������������£��ã������������С������һ�������ý��ڵ�",
        "      XXҩ���Ҿ����͸��㣬�Խ�ȼü֮����",
        "С����ϲ��§�ſ����ļ�򣺺�С�ӣ������ѣ�����Ͳ��˸�������",
        "ȥ����",        
        "С��һ�������Ƶķɳ����š�",
        "����Ц��û��ã���Ȼ����������ʧɫ��",
        "�찡����������ô�죿",
        "������������",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/gift/obj/mcyao", 1,
                           HIM "\nС���ϵ�����ǰ������˵���Ͱ���������\n\n" NOR);
        return 0;
}
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('oceny', '0004_auto_20150603_0503'),
    ]

    operations = [
        migrations.AddField(
            model_name='konkurencja',
            name='Kon',
            field=models.CharField(default=b'', unique=True, max_length=4),
        ),
    ]

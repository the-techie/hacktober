import { prop, getModelForClass, Ref } from '@typegoose/typegoose';
import { UserSchema } from '../User/user.entity';
export class BlogSchema {
  static COLL = 'Blogs';

  @prop({ trim: true })
  title: string;

  @prop({ trim: true })
  content: string;

  @prop({ default: Date.now })
  dateUpdated: Date;

  @prop({ trim: true, ref: () => UserSchema })
  createdBy: Ref<UserSchema>;
}

export const BlogModel = getModelForClass(BlogSchema, {
  schemaOptions: {
    collection: BlogSchema.COLL,
    minimize: true,
    timestamps: true,
  },
});

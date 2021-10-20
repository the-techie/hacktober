import { prop, getModelForClass, pre } from '@typegoose/typegoose';
import { genSalt, compare, hash } from 'bcrypt';
const emailRegex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;

@pre<UserSchema>('save', async function (next) {
  if (!this.isModified('password')) {
    next();
  }

  const salt = await genSalt(10);
  this.password = await hash(this.password, salt);
})
export class UserSchema {
  @prop({ required: true, trim: true })
  firstname: string;

  @prop({ trim: true, default: '' })
  lastname: string;

  @prop({ required: true, unique: true, trim: true, match: emailRegex })
  email: string;

  @prop({ trim: true, minlength: 8, required: true })
  password: string;

  getFullname() {
    return this.firstname + ' ' + this.lastname;
  }

  async authenticate(plainpassword: string) {
    return await compare(plainpassword, this.password);
  }
}

export const UserModel = getModelForClass(UserSchema, {
  schemaOptions: { collection: 'User', minimize: true, timestamps: true },
});

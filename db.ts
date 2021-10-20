import { setGlobalOptions, mongoose } from '@typegoose/typegoose';
import { Mongoose } from 'mongoose';

setGlobalOptions({
  schemaOptions: {
    minimize: true,
    id: false,
    versionKey: false,
  },
  globalOptions: {
    useNewEnum: true,
  },
});

export async function dbConnect(uri: string): Promise<Mongoose> {
  return mongoose.connect(uri);
}

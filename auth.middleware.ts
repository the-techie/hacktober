import {
  NestMiddleware,
  Injectable,
  UnauthorizedException,
  ForbiddenException,
} from '@nestjs/common';
import * as jwt from 'jsonwebtoken';
import { FastifyReply } from 'fastify';
import { IncomingRequest } from 'src/type';

@Injectable()
export class AuthMiddleware implements NestMiddleware {
  private readonly privateKey = process.env.JWT_KEY;
  use(req: IncomingRequest, res: FastifyReply, next: Function) {
    try {
      const header = req.headers.authorization;
      if (!header) {
        throw new ForbiddenException();
      }
      const token = header.split(' ')[1];
      const decoded = jwt.verify(token, this.privateKey);
      req.user = decoded as jwt.JwtPayload;
      next();
    } catch (error) {
      throw new UnauthorizedException('Unauthroized Access. Please login');
    }
  }
}
